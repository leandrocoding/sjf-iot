<?php
// $id=$_GET["id"];
// $curVal=$_GET["val"];
header('Content-Type: text/plain');  
// $_POST[val]

if(isset($_GET["val"])){
   
    $curVal = $_GET["val"];
   
    echo $curVal; 

    file_put_contents("curval.txt",$curVal);
    file_get_contents("lastCal.txt",time());
}

if(isset($_GET["up"])){
    $upLim= $_GET["up"];
    // echo json_encode($upLim, true); 
    echo $upLim; 
    file_put_contents("uplim.txt",$upLim);
                    

}
if(isset($_GET["down"])){
    $downLim=$_GET["down"];
    // echo json_encode($downLim, true); 
    echo $downLim; 
    file_put_contents("downlim.txt",$downLim);

}
if(isset($_GET["get"])){
    if($_GET["get"]=="up"){
        $upLim= file_get_contents("uplim.txt");
        echo $upLim; 

    }elseif($_GET["get"]=="down"){
        $downLim= file_get_contents("downlim.txt");
        echo $downLim; 
        // echo json_encode($downLim, true); 
    }elseif($_GET["get"]=="val"){
        $downLim= file_get_contents("curval.txt");
        echo $downLim; 
    }elseif($_GET["get"]=="time"){
        $lastcall=file_get_contents("lastCal.txt");
        $timesinze=time()-$lastcall;
        echo $timesinze;
        
    }
    
}

 
?>
