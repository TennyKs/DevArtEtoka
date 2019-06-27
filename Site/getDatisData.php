 <?php
$mysqli = new mysqli("sql7.freesqldatabase.com", "sql7296869", "fBMfGqYL7I", "sql7296869");

// $mysqli = new mysqli("sql309.byethost7.com", "b7_24105734", "mtsdevart", "b7_24105734_datisroom");

if($mysqli->connect_error) 
{
  exit('Could not connect ' );
}

$sql = "SELECT *
FROM datis";

$stmt = $mysqli->prepare($sql);
$stmt->bind_param("s", $_GET['q']);
$stmt->execute();
$stmt->store_result();
$stmt->bind_result($id, $data);
$stmt->fetch();
$stmt->close();


echo $data; 
?> 

