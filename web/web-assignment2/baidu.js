function search()
{
    var key=document.getElementById("searchkey").value;
    key="http://www.baidu.com/s?wd=" + key;
    window.location.href=key;
}

function hide(name)
{
	document.getElementById(name).style.display="none";
}