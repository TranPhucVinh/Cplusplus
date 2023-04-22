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