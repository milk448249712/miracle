<html>
	<body>
		Welcome <?php echo $_POST["name"]; ?>.<br />
		password <?php echo $_POST["password"]; ?> !
		chat room...
		<table border="1">
			<tr>
				<td>express:</td>
				<td>&nbsp&nbsp</td>
		    </tr>
		</table>
		<!-- input table-->
		<table border="1">
			<tr>
				<td>input:</td>
				<td><input type="text" name="input"></input></td>
			</tr>
			<tr align="center">
				<td colspan="2" align="center"> <input type="submit" name="submit" value="发送"></input></td>
			</tr>				
		</table>
	</body>
</html>