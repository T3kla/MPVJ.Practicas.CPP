# practica_01 bits

Given an int called 'data':

| position |  length  | what          |
| :------: | :------: | :------------ |
| [24,31]  | [8 bits] | health        |
| [16,23]  | [8 bits] | ammo          |
| [12,15]  | [4 bits] | brothers      |
| [04,11]  | [8 bits] | ---           |
|   [03]   | [1 bits] | berserker     |
|   [02]   | [1 bits] | shield        |
|   [01]   | [1 bits] | infinite_ammo |
|   [00]   | [1 bits] | god           |

Write:

```cpp
short get_ammo(const int *data)
void add_ammo(const int *data)
void is_infAmmo(const int *data)
void set_infAmmo(const int *data)
```

# practica_02 casting and ptr arithmetic

Use `static_cast<>` and pointer arithmetic.

```cpp
// given an int, separate to char array
char *to_charArray(cont int *value)
// given table, get biggest int and byte
int table[] = { 1, 3, 2, 5, 3, 0xFFFFFFFF, 2};
int biggest_int(const int *table, const int &length);
char biggest_byte(const int *table, const int &length);
// given string, invert it
void flip_str(std::string &value);
```

# practica_03

Given index to string table, return string in that index.
Given index to string table, return inverted string in that index.

# practica_04 typedef delegates

Create functions to draw and move entities.
Create entities with delegates that accept those functions.

Entities must live in the heap.
Minimum number of entities to create is 4.
Use console.h to do stuff with the console.

# practica_05 files as void\*

```cpp
void *open(const char *filename, const OpenMode &mode);
void close(void **file);
unsigned int read(const void *file, char *buffer, unsigned int n);
const char *write(const void *file, const char *buffer);
```
