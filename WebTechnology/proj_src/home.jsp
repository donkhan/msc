<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
<style>
body {
  font-family: Arial, Helvetica, sans-serif;
  margin: 0;
}

.navbar {
  overflow: hidden;
  background-color: #333;
}

.navbar a {
  float: left;
  font-size: 16px;
  color: white;
  text-align: center;
  padding: 14px 16px;
  text-decoration: none;
}

.subnav {
  float: left;
  overflow: hidden;
}

.subnav .subnavbtn {
  font-size: 16px;
  border: none;
  outline: none;
  color: white;
  padding: 14px 16px;
  background-color: inherit;
  font-family: inherit;
  margin: 0;
}

.navbar a:hover, .subnav:hover .subnavbtn {
  background-color: red;
}

.subnav-content {
  display: none;
  position: absolute;
  left: 0;
  background-color: red;
  width: 100%;
  z-index: 1;
}

.subnav-content a {
  float: left;
  color: white;
  text-decoration: none;
}

.subnav-content a:hover {
  background-color: #eee;
  color: black;
}

.subnav:hover .subnav-content {
  display: block;
}
</style>
</head>
<body>

<%@ page import="javax.naming.*" %>
<%@ page import="java.util.*" %>
<%@ page import="java.sql.*" %>
<%@ page import="javax.sql.*" %>
<%@ page import="org.h2.jdbcx.JdbcDataSource" %>
<%
   String uuid = request.getParameter("uuid");
   if (uuid == null){
         response.sendRedirect("/sample/login.html");
   }
   if(uuid.startsWith("\"")){
    uuid = uuid.substring(1,uuid.length()-1);
   }
   System.out.println("Home uuid = " + uuid);

   Context ctx = new InitialContext();
   Context initCtx  = (Context) ctx.lookup("java:/comp/env");
   DataSource ds = (DataSource) initCtx.lookup("jdbc/MyLocalDB");
   Connection con = ds.getConnection();;
   PreparedStatement stmt;
   String query = "select * from customers where uuid = ? ";
   stmt = con.prepareStatement(query);
   stmt.setString(1,uuid);
   ResultSet rs = stmt.executeQuery();
   int i = -1;
   while(rs.next()){
    i = i + 1;
   }
   rs.close();
   if(i == -1){
    response.sendRedirect("/sample/login.html");
   }

 %>

<div class="navbar">
   <a href=home.jsp?uuid="<% out.print(uuid); %>" >Home</a>
   <a href=viewproducts.jsp?uuid="<% out.print(uuid); %>" >View Products</a>
   <a href=addproduct.jsp?uuid="<% out.print(uuid); %>" >Add Product</a>
</div>


</body>
</html>
