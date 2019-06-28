 <?php
$mysqli = new mysqli("sql7.freesqldatabase.com", "sql7296869", "fBMfGqYL7I", "sql7296869");

// $mysqli = new mysqli("sql309.byethost7.com", "b7_24105734", "mtsdevart", "b7_24105734_datisroom");

if($mysqli->connect_error) 
{
  exit('Could not connect ' );
}

$sql = "SELECT *
FROM datis";



if (!$result = $mysqli->query($sql))
    echo "Error";
    
for($i = 0; $i < $result->num_rows; $i++)
{
    $row = $result->fetch_assoc();
    echo $row['usb_data']."#";
}

?> 

