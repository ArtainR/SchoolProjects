/* ===== Task 1 ===== */

function task1()
{
	let even = "";
	let odd = "";
	for(let i = 1; i < 51; i += 2)
	{
		odd += i + " ";
		even += i + 1 + " ";
	}

	alert(`${even}\n${odd}`);
}


/* ===== Task 2 ===== */

function register(form)
{
	let username = form.inputLogin.value;
	let pass1 = form.inputPass.value;
	let pass2 = form.inputPassAgain.value;

	for(;pass1 != pass2;)
	{
		document.getElementById("passError").innerHTML = "<br>Hasła nie są identyczne,<br>spróbuj ponownie<br>";
		return;
	}
	document.getElementById("passError").innerHTML = "";
	alert("Hasła są takie same.");
	alert(`Witaj, ${username}`);
	//setTimeout(() => {
	//window.location.replace("https://www.google.com");
	//}, 2000);
}

function clearForm()
{
	for(var elem of document.querySelectorAll("input:not([type='button'])")) // :]
	{
		elem.value = "";
	}
}


/* ===== Task 3 ===== */

function słupek()
{
	let n = prompt("Podaj liczbę 0-999");
	let x = Math.trunc(n / 100);
	n = n % 100;
	const bar = document.getElementById("bar");
	bar.style.backgroundImage = `linear-gradient(to right, hsl(${x / 10},1,0.5) ${n}%, hsl(${(x - 1) / 4 * 28},${(x - 1) * 28},${(x - 1) / 2 * 28}) ${n}% 100%)`
	document.getElementById("barPercent").innerHTML = `${n}%`
}


/* ===== Task 4 ===== */

function task4()
{
	let n = prompt("Podaj liczbę 1-24");

	if(n.length < 1)
	{
		return;
	}
	while(n > 24)
	{
		n--;
	}

	let pyramid = "";

	for(let i = 1; i <= n; i++)
	{
		for(let o = i; o <= n; o++)
		{
			pyramid += o + " ";
		}
		pyramid += "\n";
	}

	alert(pyramid);
}