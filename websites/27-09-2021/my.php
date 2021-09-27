<?php
	/*
		Utwórz skrypt, który obliczy sumę liczb naturalnych parzystych z zakresu od 1 do 150. Wynik wyświetl w oknie przeglądarki.
		
		Napisz skrypt, który wypisze wszystkie liczby naturalne mniejsze od liczby podanej przez użytkownika, np. jeśli użytkownik poda 5 to program wyświetli 4,3,2,1,0.
		
		Napisz skrypt wyświetlający kolejne potęgi liczby 2, aż do uzyskania wartości potęgi większej od liczby n. Wartość n podaje użytkownik, musi to być liczba naturalna większa od 0, np. jeśli użytkownik poda 5 to algorytm wyświetli 2,4,8,16,32
		
		Napisz skrypt obliczający wartość funkcji liniowej ax+b = 0 dla kolejnych x z zakresu [xpocz, xkon], gdzie a, b, xpocz, xkon podaje użytkownik (są to liczby całkowite).

	*/
	echo "Zad. 1.<br>";

	$sum = 0;

	for($i = 1; $i <= 150; $i++)
	{
		if($i % 2 == 0)
		{
			$sum += $i;
		}
	}

	echo "Suma: ".$sum."<br><br>";

	echo "Zad. 2.<br>";

	$n = abs($_POST["n"]) - 1; // for example
	$r = "";

	for($i = $n; $i >= 0; $i--)
	{
		$r = $r." ".strval($i);
	}

	echo $r."<br><br>";

	echo "Zad. 3.<br>";

	$x = 1;
	$y = $_POST["y"];
	
	for($i = $y; $i > 0; $i--)
	{
		$x *= 2;
		echo $x." ";
	}

	echo "<br><br>";
	
	echo "Zad. 4.<br>";

	$xpocz = $_POST["xpocz"];
	$xkon = $_POST["xkon"];
	$a = $_POST["a"];
	$b = $_POST["b"];

	for($i = $xpocz; $i <= $xkon; $i++)
	{
		echo ($a*$i + $b)." ";
	}
?>