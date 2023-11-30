/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    return {
         toBe : (num2) => {
            if(num2 === val){
                return true;
            }
            else throw new Error("Not Equal");
        },
    
         notToBe : (num1) =>{
            if(num1 === val) 
             throw new Error("Equal");
            else
                return true;
        }
    }
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */