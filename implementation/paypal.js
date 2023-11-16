function multiply(a) {
    return function(b) {
    return function(c) {
    return a * b * c;
    };
    };
}
    
    

    const double = multiply(2);
    const triple = multiply(3);
    const result = triple(double(4) (5)) (1);