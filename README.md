The headers that HASHBANG Productions uses. Headers are only created for classes we need, and only methods that we use are added to them. This is due to the large number of classes and methods that are broken in class dumps - this way, we manually set up the headers and they are guaranteed to work.

## Code rules
* Create headers only for what you use.
* Follow the existing coding style.
    * Objective-C properties should be in the style of `@property (attributes) type name;`
    * Objective-C methods should be in the style of `- (type)methodName:(type)variableName parameter:(type)name;`
    * Objective-C generics should be in the style of `NSDictionary<NSString *, NSArray<NSObject *> *> *variable`
    * C-style functions and variables (all symbols) shoule be declared between `__BEGIN_DECLS` and `__END_DECLS` macros
        ```c
        __BEGIN_DECLS
        int ExternalVariable;
        void ExternalFunction(int);
        __END_DECLS
        ```
* Singleton (`sharedInstance`) methods should return `instancetype`.
* Don't just copy and paste lines from class-dumps - replace `id` with the appropriate class. Also change `arg1` and the like, or in some cases class-dump-z's guessed argument names, to something more appropriate. Cycript is helpful here:

        $ cycript -p SpringBoard
        cy# [SBBaconController sharedInstance].baconCurrentlyBeingEaten.class
        @"SBBacon"

    Additionally, keep ARM64 support in mind - `float` should become `CGFloat`, `int` should become `NSInteger`, and `unsigned` should become `NSUInteger`. This is especially important when using the headers as reference for hooking.
* Any headers from an open-source library can be included here, but please note its license here in the readme.
* Pull request your changes back to this repo so others can benefit. Optional but we’d appreciate it!
