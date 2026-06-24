# Singleton Pattern

> ***The singleton pattern ensures a class has only one instance and provides a global access to it - the single instance of that class.***
> 

One of the first things we learn about “clean coding practices” is NOT to have *globals*.  They’re messy to keep track of, they get ambiguous out of context. And, concurrency would be a nightmare.

Now, *Singleton Pattern* says that we’ll only have a single **global** instance of a class?!  Is this for real??!

<aside>
💡

> One man’s constant is another man’s variable…
> 

                                               ~ Christopher Okhravi

</aside>

![image.png](SingletonPattern/image.png)

The Singleton pattern solves two problems at the same time, violating the *Single Responsibility Principle*:

1. **Ensure that a class has just a single instance**. Why would anyone want to control how many instances a class has? The most common reason for this is to control access to some shared resource—for example, a database or a file.
    
    Here’s how it works: imagine that you created an object, but after a while decided to create a new one. Instead of receiving a fresh object, you’ll get the one you already created.
    
    Note that this behavior is impossible to implement with a regular constructor since a constructor call **must** always return a new object by design.
    
2. **Provide a global access point to that instance**. Remember those global variables that you (all right, me) used to store some essential objects? While they’re very handy, they’re also very unsafe since any code can potentially overwrite the contents of those variables and crash the app.
    
    Just like a global variable, the Singleton pattern lets you access some object from anywhere in the program. However, it also protects that instance from being overwritten by other code.
    
    There’s another side to this problem: you don’t want the code that solves problem #1 to be scattered all over your program. It’s much better to have it within one class, especially if the rest of your code already depends on it.
    

### Example?

Aw hell no, this is such a disputed design pattern.
