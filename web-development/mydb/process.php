<?php

include("db.php");

if (isset($_GET["view"])) {
    $sql = "SELECT * FROM student WHERE stud_id=" . $_GET["view"];
    $result = mysqli_query($conn, $sql);
    if (!$result) {
        echo "Query failed!";
    } else {
        if ($row = mysqli_fetch_assoc($result)) {
            echo "<div class='view'><p><b>" . $row["stud_name"] . "</b> is a student who is taking the <b>" . $row["stud_course"] . "</b> program in University of San Carlos.</p></div>";
        }
    }
}

if (isset($_GET["delete"])) {
    $sql = "DELETE FROM student WHERE stud_id=" . $_GET["delete"];
    mysqli_query($conn, $sql);
}

if (isset($_POST["myname"]) && isset($_POST["mycourse"])) {
    $name = $_POST["myname"];
    $course = $_POST["mycourse"];
    insertData($name, $course, $conn);
}

function insertData($name, $course, $conn)
{
    $sql = "INSERT INTO student(stud_name, stud_course) VALUES('$name', '$course')";

    if (mysqli_query($conn, $sql)) { //If the condition
        echo "Record inserted!";
    } else {
        echo "Failed to insert! " . mysqli_error($conn);
    }
    header("Location: index.php");
}

function getData($conn)
{
    $sql = "SELECT * FROM student";
    $result = mysqli_query($conn, $sql);

    if (mysqli_num_rows($result) > 0) {
        echo "<table>";
        echo "<tr>";
        echo "<th>ID</th>";
        echo "<th>Name</th>";
        echo "<th>Course</th>";
        echo "<th>Action</th>";
        echo "</tr>";
        while ($row = mysqli_fetch_assoc($result)) {
            echo "<tr>";
            echo "<td>" . $row["stud_id"] . "</td>";
            echo "<td>" . $row["stud_name"] . "</td>";
            echo "<td>" . $row["stud_course"] . "</td>";
            echo "<td><a href='?view=" . $row["stud_id"] . "'>View</a> | <a href='?delete=" . $row["stud_id"] . "'>Delete</a></td>";
            echo "</tr>";
        }
        echo "</table>";
    } else {
        echo "Database is empty!";
    }
}
