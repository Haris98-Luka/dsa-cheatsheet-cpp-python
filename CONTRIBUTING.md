# Contributing

Thanks for helping out! Ideas that are welcome:

- A new topic from the roadmap in the README
- A missing language (Java, JavaScript) for an existing topic
- Bug fixes, clearer comments, better examples

## Rules for a new topic

1. Create a folder like `07-hash-table/`.
2. Add `README.md` (explanation + complexity table), one `.py` and one `.cpp` file.
3. Both code files must include `assert` tests and print a success message when they pass.
4. Add the topic to the table in the main README.
5. Run `bash run_all.sh` and make sure everything passes before opening a pull request.

## Code style

- Python: PEP 8, short docstrings.
- C++: C++17, no `using` of unusual headers, comment the time complexity above each function.
