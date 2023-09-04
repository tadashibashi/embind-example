// Add '& EmscriptenModule' because the type info generated via embind does not include
// the Emscripten module information
import Module from "./lib/embind_test/embind_test";

// Wait until module has been initialized to...
(Module as typeof Module & EmscriptenModule).onRuntimeInitialized = function() {

    // Instantiate C++ class
    const myClass = new Module.MyClass("hello world!", 0);

    // Call class functions
    myClass.incInt();
    myClass.incInt();
    myClass.incInt();
    myClass.incInt();

    // Print result: 4
    console.log(myClass.int);
    console.assert(myClass.int === 4);

    // Call static function
    console.log(Module.MyClass.getStringFromInstance(myClass));
    console.assert(Module.MyClass.getStringFromInstance(myClass) === "hello world!");

    // Make sure to clean up C++ class!
    myClass.delete();
};
