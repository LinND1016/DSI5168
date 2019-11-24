<?php

	$servername = "localhost";
	$username = "root";
	$password = "chuck7994";
	$dbname = "DSI5168sample";
	$sensor = $_GET['sensor'];
	// Create connection
	$conn = new mysqli($servername, $username, $password, $dbname);
	// Check connection
	if ($conn->connect_error) {
	    die("Connection failed: " . $conn->connect_error);
	}
	$sql = "INSERT INTO exmple(sensor) VALUES ('$sensor')";

	if ($conn->query($sql) === TRUE) {
    	
	} else {
	}
?>