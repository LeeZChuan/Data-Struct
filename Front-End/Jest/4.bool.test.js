const typeBool = require('./4.bool');

test('typeof number', () => {
    expect(typeBool(100)).toBe('number');
});

test('typeof boolean', () => {
    expect(typeBool(true)).toBe('boolean');
});


test('typeof string', () => {
    expect(typeBool('abcd')).toBe('string');
});