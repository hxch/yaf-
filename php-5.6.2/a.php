<?php

$a=2;

$pid = pcntl_fork();

$fp=fopen("/tmp/pc.txt","a+");

if($pid > 0){
    sleep(20);
    $a++;
    var_dump($fp);
    fwrite($fp,"parent\n");
    fclose($fp);
   
    echo "parent\n";
    echo "parent-$a\n";
}elseif($pid == 0){
    sleep(10);
    $a=$a+2;
    var_dump($fp);
    fwrite($fp,"child\n");
    fclose($fp);


    echo "child\n";
    echo "child-$a\n";
}else{
    echo "error\n";
}








