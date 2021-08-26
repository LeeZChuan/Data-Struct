var sumLine=0;
function countHeight(height) {

    sumLine = sumLine + height;

    if (height <= 0) {
        return sumLine;
    } else {
        countHeight(height / 2);

    }



}


let number=countHeight(10);
console.log(number);