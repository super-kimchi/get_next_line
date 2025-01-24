GNL is basically immitation of [[lseek()]] function in c

## limitation
## “What if the file is huge or has a monstrously long line?”

This is the downside: if the file has a single line that’s truly enormous, you’ll be forced to allocate enough memory to hold that entire line in one go. You can’t break it up across multiple calls, because the spec demands that **one call returns exactly one complete line**. If that line doesn’t have a newline until 2GB in, you’d (in theory) keep growing your static buffer up to 2GB. On a system with limited RAM, that’s going to fail.

In other words:

- **Yes**, if you keep reading until you find a `\n`, you _must_ store everything until that point.
- In real-world scenarios, if lines can be arbitrarily large, this can lead to memory exhaustion. That’s just a **limitation** of the specification. Usually, in practice, text lines are of a reasonable length.

## implementation

1. **Dynamic “Line-by-Line” Stash (Approach #1)**
    
    - You keep a _dynamically sized_ stash (static buffer) that **only** holds leftover data and whatever new data you’ve just read.
    - Whenever you find a line, you **extract** it (malloc for the line), then **re-malloc** the stash just for the leftover.
    - This way, you never keep **the entire file** in memory at once—only enough for the longest line (plus partial leftover).
    - _Advantages_:
        - Fairly straightforward to implement.
        - Won’t explode to the entire file’s size if there are frequent newlines.
        - Commonly used in GNL.
    - _Disadvantages_:
        - Repeated malloc/free calls can be frequent for very short lines.
2. **Whole File Accumulation (Approach #2)**
    
    - You read and append _everything_ into one large stash, keeping track of your current “position” (index) for which line you’re returning.
    - You only “slice out” or “point to” each new line, but fundamentally, you’re storing the **entire file** in memory.
    - _Advantages_:
        - Simple logic for slicing lines if the file is small.
    - _Disadvantages_:
        - Extremely **risky** or **inefficient** for large files: you might blow up memory.
        - Goes against the GNL principle of “read as little as possible.”
3. **Fixed-Size Static Buffer + Shifting (Approach #3)**
    
    - You have a statically allocated buffer of some size (e.g., 1024 bytes).
    - After each read, if a line is found, you “remove” it by shifting leftover bytes to the front.
    - If a line doesn’t fit, you expand the buffer.
    - _Advantages_:
        - In principle, can work with minimal extra allocations if lines are typically smaller than your chosen buffer size.
    - _Disadvantages_:
        - “Pointer gymnastics” (lots of manual shifting) can be error-prone.
        - If there’s a huge line, you still end up expanding multiple times anyway, so you don’t really save yourself from reallocation complexity.

---

### Which One Is “Best”?

- **Approach #1** is typically the **standard** in 42’s Get Next Line (and similar exercises), because:
    
    1. It handles arbitrarily long lines by dynamically growing.
    2. It doesn’t blow up to the entire file size unless you truly have only _one_ enormous line (which is unavoidable if you have to return that line in one piece).
    3. It’s conceptually simpler than the pointer-shifting approach, yet doesn’t risk reading the entire file into memory at once.
- **Approach #2** is clearly not recommended for large files.
    
- **Approach #3** is doable but can be trickier to implement (shifting data is more error-prone), and you still have to expand the buffer if you meet a line bigger than the initial capacity.
    

So yes, your summary is on point:

1. Approach #1 (dynamic) is the **go-to** for GNL.
2. Approach #2 is memory-heavy (risky).
3. Approach #3 can work, but involves “pointer gymnastics” and repeated expansions anyway.

 The **static buffer** (or “stash”) **changes size dynamically** as you:

1. **Append** newly read data.
2. **Extract** a line (and possibly keep leftover).

Every time you find a newline in your stash, you:

- **Malloc** enough space for the line (up to `\n`)—return (or “print”) that line.
- **Malloc** space for the leftover (if any) that remains _after_ the newline.
- **Free** the old stash and set the stash pointer to the newly allocated leftover.

Then, when you read again, you’ll be appending new bytes to whatever leftover is in the stash. Hence your stash grows (or shrinks) with each operation. That’s the standard pattern when you can’t call `realloc()` directly:

- You “simulate” `realloc` by allocating a bigger (or smaller) buffer, copying the old data plus new data (or leftover), and freeing the old buffer.

### Implementation example

- **Initial**: `stash = NULL`.
    
- **First read** (8 bytes): stash becomes 8 bytes. You find a newline at index 6 → line is size 7 (including `\n`), leftover size 1. So you:
    
    1. Malloc(7) for the line, copy it, return (or “print”).
    2. Malloc(1) for leftover, copy that leftover to it.
    3. Free the old 8-byte stash.
    4. `stash = leftover;` (size 1).
- **Second read** (8 bytes): leftover was 1, plus new 8 bytes → you combine into a new 9-byte stash. If you find another newline at, say, index 3, you extract a 4-byte line, and have leftover of 5 bytes, etc.
    

So yes, you can see how the stash might go from 8 → 2 → 10 → (extract line) → leftover 6 → next read 8 → stash 14, etc. It’s **all about** manually resizing the stash to hold “old leftover + newly read bytes” or “new leftover after extracting a line.”

That’s fundamentally how the **dynamic storage** works in `get_next_line()` when you’re only allowed `read`, `malloc`, and `free`.

## sudo code
A **simplified** high-level approach often looks like this:

1. **Check if `buffer` has data** (from a previous call):
    - If it **already has** a newline, immediately extract the line and update the buffer (leftover).
    - If no newline, proceed to step 2.
2. **Read** from `fd` into a **temporary** array (`temp`):
    - Handle **errors** (`read` returns −1-1−1) by freeing what’s needed and returning `NULL`.
	    - ==Important to free temp when the read returns 0 or -1==
    - If **EOF** (`read` returns 0) and there’s leftover data in `buffer`, return that leftover as the final line; otherwise `NULL`.
3. **Append** the newly read bytes to `buffer`:
    - Allocate a new buffer big enough for “old buffer + newly read bytes.”
    - Copy old buffer + new data together, free the old buffer, then point `buffer` to the new combined buffer.
	    - strjoin()
	    - ==important to free old buffer before u assign the newly created concatenated buffer==
4. **Check again** if `buffer` now contains a newline:
    - If yes, **extract** the line, update leftover, and return the line.
    - If no, keep reading (go back to step 2) until you find a newline or hit EOF.

## Things to consider
1.Always free the dynamically allocated memory if its no longer used 
	- old stash buffer
	- temp when read error
	- whenever the malloc error occurs
		- free everything on the heap and return (0) to print NULL
2.Be careful with Dangling stash pointer
	when u free the buffer due to error or resetting the stash You always have to reinitialize dangling buffer to null or else it will keep being alive and u are not gonna be able to reset the pointer even after freeing old buffer.
	You have to manually initialize to null or else it might lead to double freeing when another gnl call happens.
	reference [[static buffer dangling pointer reset]]