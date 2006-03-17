<?php
 
 function MostraTamanhosDeFormaAmigavel($tamanho) {
   $unidade = "bytes";
   
   if ($tamanho > 1024) {
       $tamanho = ($tamanho / 1024);
       $unidade = "KB"; }
   if ($tamanho > 1024) {
       $tamanho = ($tamanho / 1024);
       $unidade = "MB"; }
   if ($tamanho > 1024) {
       $tamanho = ($tamanho / 1024);
       $unidade = "GB"; }
   if ($tamanho > 1024) {
       $tamanho = ($tamanho / 1024);
       $unidade = "TB"; }
   
   $tamanho = round($tamanho, 0);
   return $tamanho." ".$unidade;
}
 
?>
