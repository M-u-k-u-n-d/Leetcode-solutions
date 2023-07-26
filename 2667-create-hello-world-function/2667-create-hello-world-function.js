/**
 * @return {Function}
 */
var createHelloWorld = function() {
    return function(val) {
        val = "Hello World";
        return val;
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */