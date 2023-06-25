# Important notes

Current searching and appending methods implemented in those 2 examples ([Employee management by file](#employee-management-by-file) and [Employee management with OOP](#Employee%20management%20with%20OOP)) are not efficient as generally a file is used to store all information then this file is opened for appending at its end of it (for adding new employee) or searching at each line of the file (for search operation). This generally results in high time complexity. A better solution for that can be:
* Display: Store the data of each employee in a specific file format like JSON, dictionary. The display operation will then read all those files to display in the column
* Search: Arrange the data into a descending or ascending order then perform a search method, e.g binary search

# Employee management by file

## Features

* Data is stored in ``txt`` file
* Add new employee information
* Search: by ID, by name and by salary

As using txt to store database, we have no choice but to use ``fileStreamIn.seekg(44)``

``employee.txt``

```
ID                Name              Salary
```

## TXT file

**For searching feature**: As using ``txt`` file to store data, for proper content searching, the entered name should not include space.

**For editing feature**: As the data is stored in a file, you can't edit the content of a single line belong to an opening a file to read. For more information, refer to ``Unable to handle in/out at the same time with ifstream and ofstream`` in ``File stream/ofstream and ifstream.md``.

# [Employee management with OOP](Employee%20management%20with%20OOP)

## Features

* Data is stored in ``txt`` file
* Add new employee information
* Search: by ID, by name and by salary
* Handle adding and searching feature with OOP

``database.txt``

```
ID                Name              Salary 
```
