function checkTriangle(form)
{
	let a = form.inA.value;
	let b = form.inB.value;
	let c = form.inC.value;

	if(a == b && b == c)
	{
		alert("Trójkąt jest równoboczny");
	}
	else if (a == b || b == c || a == c)
	{
		alert("Trójkąt jest równoramienny");
	}
	else
	{
		alert("Trójką jest różnoboczny");
	}
}