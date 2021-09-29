
/* 5、如上，如何实现点击每个li然后隐藏，并显示data_id的值
6、如何阻止继续冒泡
 */
var ul=document.getElementById('parent');
var li=document.getElementsByTagName('li');


function show(){
	// console.log(ul);
	console.log(li[0]);
	console.log(li[1].value);
	if(ul.style.display=='none')
	{
		ul.style.display='block'
	}else{
		
	}
}

function click(){
	for(let i =0 ;i<li.length;i++)
	{
		li[i].onclick=()=>{
			console.log(li[i]);
			console.log(li[i]);
			li[i].style.display='none';
		}
	}
}


show();
click();


