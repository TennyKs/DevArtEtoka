 <?php
$mysqli = new mysqli("remotemysql.com", "pJtsHBduHR", "BTKyT1EvRA", "pJtsHBduHR");
//$mysqli = new mysqli("sql309.byethost7.com", "b7_24105734", "mtsdevart", "b7_24105734_datisroom");

if($mysqli->connect_error) 
{
    //echo "test";
  //echo "Errno: " . $mysqli->mysqli_connect_error();
  //echo "Error : " . mysqli_connect_error() . PHP_EOL;
  echo "error ".$mysqli->connect_error;
  exit('Could not connect ' );
}

$sql = "SELECT *
FROM data";

$stmt = $mysqli->prepare($sql);
$stmt->bind_param("s", $_GET['q']);
$stmt->execute();
$stmt->store_result();
$stmt->bind_result($type, $number);
$stmt->fetch();
$stmt->close();

/*echo "<table>";
echo "<tr>";
echo "<th>CustomerID</th>";
echo "<td>" . $type . "</td>";
echo "<th>CompanyName</th>";
echo "<td>" . $number . "</td>";
echo "</table>";*/

echo "type ".$type;
echo "num ".$number; 
?> 
