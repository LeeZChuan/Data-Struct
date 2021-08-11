//描述：给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。


let nums=[1,8,2,5,7,9,6];
let target=11;

//使用遍历的方式
function getIndex(nums,target){
    let indexList=[];
    for(let i=0;i<nums.length;i++)
    {
        let tempnum=target-nums[i];
        //循环
        for(let j=i;j<nums.length;j++)
        {
            if(nums[j]==tempnum){
                indexList.push(i,j);
                console.log(indexList)
                return indexList
            }
        }
    }
    return null;
}


//使用indexof
function getIndex1(nums,target){
    for(let i=0;i<nums.length;i++)
    {
        let tempnum=target-nums[i];
        //循环
        if(nums.indexOf(tempnum)>=0)
        {
            return [i,nums.indexOf(tempnum)];
        }
    }
    //如果没有
    return null;
}

getIndex(nums,target);
let a=getIndex1(nums,target);

console.log(a);