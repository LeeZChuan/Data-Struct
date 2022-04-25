const Typeof = require('./6.string');
const concat = require('./6.string');

// test('typeof abc', () => {
//     expect(Typeof('abc')).toBe(true);
// });

test('concat a+b', () => {
    expect(concat('ab','cd')).toBe('abcd');
});
