// Counts the number of times pattern occurs in string
// Example: count("aybabtu", "bab") -> 1
// Example: count("aaaaaa", "aa") -> 5
int count(char *string, char *pattern) {
    // TODO
}

// Checks if string starts with prefix
// Example: starts_with("aybabtu", "ayb") -> 1
// Example: starts_with("aybabtu", "lol") -> 0
int starts_with(char *string, char *prefix) {
    // TODO
}

// Checks if string ends with suffix
// Example: ends_with("aybabtu", "btu") -> 1
// Example: ends_with("aybabtu", "lol") -> 0
int ends_with(char *string, char *suffix) {
    // TODO
}

// Concatenates the strings in the array into a single string
// Example: {"apina", "banaani", "cembalo"} -> "apinabanaanicembalo"
char* concat(char **array, int n) {
    // TODO
}

// Returns the first position where pattern occurs in string
//   - If pattern doesn't occur in string, return -1
// Example: find("aybabtu", "bab") -> 2
// Example: find("aybabtu", "lol") -> -1
int find(char *string, char *pattern) {
    // TODO
}

// Creates a string that repeats pattern n times
// Example: repeat("abc", 4) -> "abcabcabcabc"
char* repeat(char *pattern, int n) {
    // TODO
}

// Removes spaces around the string
// Example: trim(" aybabtu   ") -> "aybabtu"
char* trim(char *string) {
    // TODO
}

// Replaces characters a-z with A-Z in string
// Example: upper("aybabtu") -> "AYBABTU"
// Example: upper("AyBaBtU") -> "AYBABTU"
char* upper(char *string) {
    // TODO
}

// Replaces characters A-Z with a-z in string
// Example: upper("AYBABTU") -> "aybabtu"
// Example: upper("AyBaBtU") -> "aybabtu"
char* lower(char *string) {
    // TODO
}

// Returns a substring from the string
//   - Stop if the position goes past the end of the string
// Example: substr("aybabtu", 2, 3) -> "bab"
// Example: substr("aybabtu", 10, 3) -> ""
// Example: substr("aybabtu", 2, 10) -> "babtu"
char* substr(char *string, int start, int length) {
    // TODO
}

// Replaces all occurrences of old with new in string
//   - Don't replace an already replaced character
// Example: replace("aybabtu", "bab", "lol") -> "ayloltu"
// Example: replace("aa", "a", "aa") -> "aaaa"
char* replace(char *string, char *old, char *new) {
    // TODO
}

// Applies ROT13 transformation to string
//   - Rotate each letter (a-z and A-Z) 13 steps
//   - More information: https://en.wikipedia.org/wiki/ROT13
// Example: rot13("aybabtu") -> "nlonogh"
char* rot13(char *string) {
    // TODO
}

// Concatenates the strings into a single string using a delimiter
// Example: {"apina", "banaani", "cembalo"} '|' -> "apina|banaani|cembalo"
char* join(char **array, int n, char delimiter) {
    // TODO
}

// Splits the string into an array using a delimiter
//   - Return the array length
//   - Reserve memory for the array
// Example: "apina|banaani|cembalo" '|' -> {"apina", "banaani", "cembalo"}
int split(char* string, char delimiter, char*** array) {
    // TODO
}

// Sorts the given array of strings
//   - Use strcmp to compare the strings
// Example: {"all", "your", "base", "are", "belong", "to", "us"} ->
//          {"all", "are", "base", "belong", "to", "us", "your"}
void sort_strings(char **array, int n) {
    // TODO
}
