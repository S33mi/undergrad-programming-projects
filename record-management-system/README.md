# Record Management System (C++ File Handling)



Console-based CRUD application for managing student/employee/reservation records using text file storage.



Features:

- Add new record

- View all records

- Search by ID/name

- Update record

- Delete record

- Data saved to records.txt (std.txt for students case)

The output will look like this

---- Welcome to Record Management System ----

Reading data from "filename.txt"...

File opened successfully and records of 6 students have been read.

Menu

1. Display list of all students

2. Display student record(s) having Maximum SGPA

3. Display student record(s) having Minimum SGPA

4. Search by Roll Number

5. Update a Student record

6. Quit

Enter your choice: 1

Roll No. Name Courses SGPA

...

Note: List will contain the records of all the students.


Technologies: C++, file I/O (fstream), structs



How to compile & run:

```bash

g++ main.cpp -o record_manager

./record_manager

