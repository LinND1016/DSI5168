<?php
header("Content-Type:text/html; charset=utf-8");
$servername = "localhost";
$username = "root";
$password = "chuck7994";
$dbname = "MatsuVillage";

$conn = new mysqli($servername, $username, $password, $dbname);
	// Check connection
	if ($conn->connect_error) {
    	die("Connection failed: " . $conn->connect_error);
	} 
mysqli_query($conn , "set names utf8"); 

?> 