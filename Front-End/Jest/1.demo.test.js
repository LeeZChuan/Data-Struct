import addDivToBody from "./1.demo";

import $ from 'jquery';

test('测试adddivtobody()', () => {
    addDivToBody();
    addDivToBody();
    expect($('body').find('div').length).toBe(2);
  });