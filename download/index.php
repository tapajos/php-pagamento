<?
##################################################################
####  Autor: Marcos Tapajos                                   ####
####  Email: tapajos@dcc.ufrj.br                              ####
####  Data:  09/03/2005                                       ####
####  Este script é para livre distribuição. Caso ache alguma ####
####  forma melhor de fazer isso favor reportar.              ####
##################################################################
session_start();
include '../funcoes/funcoesDeArquivos.inc';
include '../funcoes/funcoesPostEgets.inc';
include '../funcoes/funcoesDeLogin.inc';
variaveisViaPost();
validaLoginTosco($login,$senha);
?>
<html> 
<head> 
<style type="text/css"> 
	A:hover{color:#fa8f00;} 
	a{text-decoration:none} 
</style> 
<title>MARCOS TAPAJOS DOWNLOAD PAGE !</title> 
<body>
<blink>
	<center>
		<h1>
			MARCOS TAPAJOS DOWNLOAD PAGE !
		</h1>
	</center>
</blink>


<? if (!verificaLogado()) { ?>
	
  <form action="index.php" method="post">
  <center>  
  <table>
    <tr>
      <td>Login: </td><td><input type="text" name="login" size="40" maxlength="40"/></td>
    </tr>
    <tr>
      <td>Senha: </td><td><input type="password" name="senha" size="40" maxlength="40"/></td>
    </tr>
    <tr>
      <td><input type="submit" value ="confirmar"/></td><td><input type="reset" name="name" value="limpar"/></td>
    </tr>
  </table>
  </center>
  </form>
  
<? } else { ?>

<table width="700" border="1" cellpadding="0" cellspacing="0" bordercolor="#CCCCCC" align="center"> 
  <tr bgcolor="#666666"> 
    <td width="450" align="center">
    		<b>
    			<font color="#FFFFFF">
    				Arquivo
    			</font>
    		</b>
    	</td> 
    <td width="150" align="center">
    		<b>
    			<font color="#FFFFFF">
    				Data e hora de envio do arquivo
    			</font>
    		</b>
    	</td> 
    <td width="100" align="center">
    		<b>
    			<font color="#FFFFFF">
    				Tamanho
    			</font>
    		</b>
    	</td> 
  </tr> 

<?php 
$listar="../arquivos"; //colocar aqui o nome do diretório a ser listado
$diretorio=$id;
if ($dir=opendir("$listar/".$diretorio)){ 
	while(($arquivos=readdir($dir)) !== false){ 
		if ($arquivos <> "." && $arquivos <> ".." ){ 
			$tamanho[] = filesize("$listar/".$diretorio."/".$arquivos); 
			$data_hora[] = filemtime	("$listar/".$diretorio."/".$arquivos); 
			$nome_arquivo[] = $arquivos; 
		} 
	} 
	closedir($dir); 
} 
 
$n_arquivos = count($data_hora); 
arsort($data_hora); 
reset($data_hora); 
$indice=0;
while (list ($chave, $valor) = each ($data_hora)){ 
?>
  <form name="form<?echo $indice;?>" action="index.php" method="post">
  <tr> 
    <td>
    		<input type="hidden" name="id" value="<?echo $diretorio."/".$nome_arquivo[$chave];?>">
     	<a href="<?php 
     		if (!is_dir($listar."/".$diretorio."/".$nome_arquivo[$chave])) {
     			echo "$listar".$diretorio."/".$nome_arquivo[$chave];
     		}
     		else {
     			echo "#\" onclick='form".$indice.".submit();'";
     		} ?>">
     		<?php echo $nome_arquivo[$chave]; ?>
     	</a>
	</td> 
    <td align="center" >
		<?php if (!is_dir($listar."/".$diretorio."/".$nome_arquivo[$chave])){
			echo date("d/m/Y-H:s",$valor);
		}
		else {
			echo ("Diretorio");
		} ?> 
    </td> 
    <td align="center" >
		<?php if (!is_dir($listar."/".$diretorio."/".$nome_arquivo[$chave])){
			echo MostraTamanhosDeFormaAmigavel($tamanho[$chave]);
		}
		else {
			echo ("Diretorio");
		}?> 
    </td> 
  </tr> 
  </form>
<?php 
$indice++;
} 
clearstatcache();
?>
</table>
<br>
<br>
<center>
	<?
	$gera_novo_id = explode ("/",$diretorio);
	for ($i=1;$i<sizeof($gera_novo_id)-1;$i++){
		$new_id = $new_id."/".$gera_novo_id[$i];
	}
	?>
	<form name="formback" action="index.php" method="post">
		<input type="hidden" name="id" value="<?echo ($new_id);?>" size="40" maxlength="40"/>
		Clique <a href="#" onclick="formback.submit();">aqui</a> para voltar um nivel na navegação pelos diretorios
	<form>
</center>
<? }?>
</body> 
</html> 
