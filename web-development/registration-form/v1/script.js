function clear_details() {
    document.getElementById("span1").innerHTML = "";
    document.getElementById("span2").innerHTML = "";
    document.getElementById("span3").innerHTML = "";
    document.getElementById("span4").innerHTML = "";
    document.getElementById("span5").innerHTML = "";
}

function submit_details() {
    document.getElementById("span1").innerHTML = document.getElementById("fullName").value;
    document.getElementById("span2").innerHTML = document.getElementById("course").value;
    document.getElementById("span3").innerHTML = document.getElementById("emailAddress").value;
    document.getElementById("span4").innerHTML = document.getElementById("previousSchool").value;
    document.getElementById("span5").innerHTML = document.getElementById("applicationReason").value;
}