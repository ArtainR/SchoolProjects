function register(form)
{
	let username = form.inputLogin.value;
	let pass1 = form.inputPass.value;
	let pass2 = form.inputPassAgain.value;

	if(pass1 == pass2)
	{
		alert("Hasła są takie same.");
		alert(`Witaj, ${username}`);
		setTimeout(() => {
			window.location.replace("https://www.google.com")
		}, 2000);
	}
	else
	{
		alert("Hasła są różne.");
		alert("Get dunked on.");
		setTimeout(() => {
			window.location.replace("https://www.youtube.com/watch?v=dQw4w9WgXcQ")
		}, 2000);
	}
}

function clearForm()
{
	for(var elem of document.querySelectorAll("input:not([type='button'])")) // :]
	{
		elem.value = "";
	}
}

function hasEqualSides()
{
	
}