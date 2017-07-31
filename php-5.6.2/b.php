<?php


function daemon()
{
    $pid = pcntl_fork();
    if($pid < 0){
        die("fork(1) failed!\n");
    }elseif($pid > 0){
        exit; //让终端启动的进程退出
    }
     chdir("/"); //改变当前目录为根目录
    umask(0); //重设文件权限掩码
    //建立一个有别于终端的新session以脱离终端
    $sid = posix_setsid();
    if (!$sid) {
        die("setsid failed!\n");
    }
    $pid = pcntl_fork();
    if($pid < 0){
        die("fork(1) failed!\n");
    }elseif($pid > 0){
        exit; //父进程退出, 剩下子进程成为最终的独立进程
    }
    //关闭标准I/O流
    if (defined('STDIN')) {
        fclose(STDIN);
    }
//    if (defined('STDOUT')){
  //      fclose(STDOUT);
   // }
    if (defined('STDERR')) {
        fclose(STDERR);
    }
}
daemon();
 
sleep(10);
file_put_contents("/tmp/hup.txt","hahaha");
echo 456;



