const Typeof = require('./2.typeof');

test('funcation()', () => {
  expect(Typeof(function(){})).toBe(Function);
});
