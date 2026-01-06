1.1. A new operator could be created and it just works on the stored number immediatly and does not ask for a second number.
1.2. The function `strcmp` could be used in place of the 'switch' statement (although technically array).
1.3. The type of `accumulator` and `current` can be changed to double.
1.4. **no.**
1.5. Similar to M and A, it would be a unary operator that just sets the stored value to 0.
1.6. Operations could be stored in some list and parentheses could be converted to reverse-polish-notation.
2.1. Depends on archetecture, if using 32 bit ints, −2,147,483,648 and 2,147,483,647.
2.2. Characters could be stored holding the decimal digit making printing very easy. Unsigned numbers could also be stored in bytes allowing for more density.
2.3. The `*` operator will be the most dificult to impliment because it would require a lot of looping, more than `+` or `-` would need.
2.4. Typing in "abcd1234" errors first because the first parts are not numbers. Typing in "1234abcd" would read the first half in as a valid number then error on the second half when another digit or operation is requested
2.5. Bitwise and, bitwise or, bitwise not, bitwise exclusive or, bitshift left, bitshift right, division, and modulo.
2.6. boring c++ stuff.
2.7. boring c++ stuff, c hath no operator overloads.
3.1  When trying to open a nonexistant file, the returned file pointer is null. When an interger is overflowed, the computer usually stays silent and just wraps it around. When dividing by zero, computers may either go to some state like returning zero but they may also segfault or throw an inturrupt. Returning a null file pointer is detectable and handelable. Inturrupts are also detectable but require more code to handle. The try-except model of error handeling is similar to this. When just returning zero, it is quite hard to detect, making it a bad choice.
3.2. Divide by zero and bad declaration are the only errors I can think of that would be reasonable for BigInt to have.
3.3. Real time calculations, such as graphics when rendering for a game, benefit most because old data is not useful.
3.4. Input is the most flexible, allowing an user to correct the issue, but inexperiences users may struggle becasue they do not understand the internals. Halting the program is best for non-experienced users and for automated tasks because it is the simplest, however its simplicity makes it hard to correct if you know how to. Ignoring the error is best real time data that is irrelivent if old but results in lost data.
3.5. Having a variable to store the condition allows for a lot of flexability in picking one of the three methods above but it requires more explicit specification making code more verbose.
4.1. Storing in a vector<char> makes printing easier (you can just print vector.data() as long as it null terminated) storing in an vector<int> will allow for far more data density but will require an overhaul of the printing method.
4.2. A bool could store if it is negative. Alternatively, a char could hold a '-' or a '+'.
4.3. Not writing it, but the main error would be getting a digit that is out of range.
4.4. GetDigit only allows for getting a singular digit. To impliment operator== along with <, <=, >, and >=, a basic version of strcmp could be created.
4.5. I have no clue what apvector is. It sounds like a bloated reimplimentation of the standard utility written by college board, so it wouldn't be better to use.
