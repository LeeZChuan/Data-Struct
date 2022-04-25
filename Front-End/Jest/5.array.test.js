const Typeof = require('./5.array');
const max = require('./5.array');
const min = require('./5.array');

// test('typeof Array', () => {
//     expect(Typeof([0, 1, 2])).toBe(true);
// });

test('Array max', () => {
    expect(max([3, 1, 2])).toBe(1);
});


test('Array min', () => {
    expect(min([0, 1, 2])).toBe(0);
});