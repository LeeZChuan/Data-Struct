const sum = require('./3.number');
const difference = require('./3.number');

test('adds 1 + 2 to equal 3', () => {
  expect(sum(1, 2)).toBe(3);
});

// test('adds 3 - 2 to equal 1', () => {
//     expect(difference(3, 2)).toBe(1);
//   });