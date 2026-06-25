# Factory Pattern

### Why Do We Need It?

If at some point in a program you need an instance of a class… now, unless you know which class to instantiate at that point, it’s great.  You could do *Dependency Injection* and be done with it.
But, what if there’s some business logic involved to decide which class to instantiate?  And, what if the construction was also complex and based on some business logic?

So this pattern basically solves the problem of creating an object - without you caring much about why, when and, where?  You want to defer all these tasks to the *factory*. 

> ***The Factory method Pattern defines an interface for creating an object.  But, lets sub-classes decide which class to instantiate.  Factory method lets a class defer instantiation to sub-classes.***
> 

A simple factory method pattern would be very intuitive in complex scenarios where you’re creating objects based on certain business logic at separate places in your code.  You’d intuitively think of pulling that logic out in its own class and use that instead of having lots of duplicate lines of code all over the code-base.  That’s fine and dandy unless you now want to achieve *runtime polymorphism*.  This is where the real power of factory method pattern comes into picture.

There’s actually a very minimal, added layer of abstraction to what we described just above which gives us the power to achieve *runtime polymorphism*.

![image.png](Factory%20Pattern/image.png)

1. The Product declares the interface, which is common to all objects that can be produced by the creator and its subclasses.
2. Concrete Products are different implementations of the product interface.
3. The Creator class declares the factory method that returns new product objects. It’s important that the return type of this method matches the product interface.
You can declare the factory method as abstract to force all subclasses to implement their own versions of the method. As an alternative, the base factory method can return some default product type.
Note, despite its name, product creation is not the primary responsibility of the creator. Usually, the creator class already has some core business logic related to products. The factory method helps to decouple this logic from the concrete product classes. Here is an analogy: a large software development company can have a training department for programmers. However, the primary function of the company as a whole is still writing code, not producing programmers.
4. Concrete Creators override the base factory method so it returns a different type of product.
Note that the factory method doesn’t have to create new instances all the time. It can also return existing objects from a cache, an object pool, or another source.