# Smart pointers

Smart pointers are special functions in c++ that automate the process of dynamically freeing memory.

### Shared_ptr

You can create this pointer by using `std::make_shared<Type>(value)` and store it in `std::shared_ptr<Type>`
You can create multiple shared pointers to one space in memory and memory will be free when will the last of them be released.

