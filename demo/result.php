<?php
	$servername = "localhost";
	$username = "root";
	$password = "chuck7994";
	$dbname = "DSI5168sample";

	// Create connection
	$conn = new mysqli($servername, $username, $password, $dbname);
	// Check connection
	if ($conn->connect_error) {
	    die("Connection failed: " . $conn->connect_error);
	}
?>
<html>
<head>
	<meta http-equiv="refresh" content="5" />
</head>
<style>
table, th, td {
  border: 1px solid black;
  width: 500px;
  margin: 5% auto;
}
</style>
<body>
	<table>
		<tr>
			<th>No</th>
		    <th>sensor</th> 
		    <th>time</th>
		</tr>
		<?php
			$sql = "SELECT * FROM exmple";
			$result = $conn->query($sql);

			if ($result->num_rows > 0) {
			    // output data of each row
			    while($row = $result->fetch_assoc()) {
			        echo "<tr>";
			        	echo "<td>".$row['id']."</td>";
			        	echo "<td>".$row['sensor']."</td>";
			        	echo "<td>".$row['timestamp']."</td>";
			        echo "</tr>";
			    }
			} else {
			    echo "0 results";
			}
		?>
	</table>
</body>
</html>