# get_next_line

## Description
The `get_next_line` project is part of the 42 School curriculum. It implements a function in C that reads a line from a file descriptor (e.g., a file or `stdin`) and returns it to the caller. The function handles incremental reading, managing buffers to process files of arbitrary size. This project includes two versions:

- **Standard Version**: Reads lines from a single file descriptor at a time.
- **Bonus Version**: Supports reading from multiple file descriptors simultaneously, maintaining the state of each.

The project adheres to the Norminette rules, including a **maximum of 25 lines per function**.

## Objective
The goal is to create a function that:
- Reads a line (terminated by `\n` or end-of-file) from a file descriptor.
- Returns the read line as a dynamically allocated string.
- Manages reading efficiently using a static buffer.
- In the bonus version, handles multiple file descriptors without mixing their buffers.

## Requirements
- **Language**: C
- **Norminette**: All functions must have at most 25 lines and comply with Norminette rules.
- **Compilation**: Use `-Wall -Wextra -Werror` flags and define `BUFFER_SIZE` (e.g., `-D BUFFER_SIZE=42`).
- **Memory Management**: No memory leaks, verifiable with Valgrind.
- **Supported File Descriptors**: Files, `stdin`, and multiple file descriptors (bonus version).
- **Return Values**:
  - A string containing the line read (including `\n`, if present).
  - `NULL` if there is nothing more to read or an error occurs.

## Files
- **Standard Version**:
  - `get_next_line.c`: Main implementation.
  - `get_next_line.h`: Header file with function prototype and dependencies.
  - `get_next_line_utils.c`: Helper functions.

- **Bonus Version**:
  - `get_next_line_bonus.c`: Main Implementation for the bonus version.
  - `get_next_line_bonus.h`: Header file for the bonus version.
  - `get_next_line_utils_bonus.c`: Helper functions for the bonus version.

- **Test File**:
  - `main.c`: A test program that reads lines from multiple files in an interleaved manner (bonus version) or sequentially (standard version).

## Usage
1. **Compile**:
   ```bash
   ./run.sh
   ```

2. **Run the Program**:
   
   Run standard:
   ```bash
   ./gnl file1.txt
   ```

   Run bonus:
   ```bash
   ./gnl_bonus file1.txt file2.txt file3.txt
   ```


## Testing
To thoroughly test the project, consider the following cases:
- **Multiple Files**: Read from several files interleaved (bonus version).
- **Empty Files**: Test with empty files (`touch empty.txt`).
- **Long Lines**: Test with lines longer than `BUFFER_SIZE`.
- **Different BUFFER_SIZE Values**: Compile with `-D BUFFER_SIZE=1`, `42`, and `9999`.
- **Invalid File Descriptors**: Test with non-existent files or invalid `fd`s.
- **stdin**: Test reading from standard input (`./test_gnl < file1.txt`).


## Notes
- **Function Line Limit**: Each function is designed to respect the 25-line limit, which may require careful structuring of the code.


## Author
- **Name**: Nuno Taboada
- **Email**: nunotaboada@gmail.com

This project was completed as part of the 42 school curriculum

<a href="https://www.42porto.com/pt/">
 	<img alt="Static Badge" src="https://img.shields.io/badge/_-Porto-_?style=for-the-badge&logo=42&labelColor=black&color=gray&link=https%3A%2F%2Fwww.42porto.com%2Fpt%2F">	
</a>
