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
   System.out.println("Add Product uuid = " + uuid);
   String product_id = request.getParameter("product_id");
   String product_name = request.getParameter("product_name");
   String product_category = request.getParameter("product_category");
   String product_price = request.getParameter("product_price");
   System.out.print("new Product id " + product_id + " product name " + product_name);

   if( product_id == null) product_id = "";
   if( product_name == null) product_name = "";
   if( product_category == null) product_category = "";
   if( product_price == null) product_price = "";


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

   if(!product_id.equals("") && !product_name.equals("") && !product_category.equals("") && !product_price.equals("")){
     query = " insert into products (id, name, category, price )"
                     + " values (?, ?, ?, ?)";
      stmt = con.prepareStatement(query);
      stmt.setString(1,product_id);
      stmt.setString(2,product_name);
      stmt.setString(3,product_category);
      stmt.setDouble(4,Double.parseDouble(product_price));

      stmt.execute();
   }

 %>

<div class="navbar">
   <a href=home.jsp?uuid="<% out.print(uuid); %>" >Home</a>
   <a href=viewproducts.jsp?uuid="<% out.print(uuid); %>" >View Products</a>
   <a href=addproduct.jsp?uuid="<% out.print(uuid); %>" >Add Product</a>
   <a href=searchproduct.jsp?uuid="<% out.print(uuid); %>" >Search Product</a>
</div>

<form action="/sample/addproduct.jsp" method="get">

<br><br><br><br>
Product ID    : <input type="text" name="product_id">
<br><br>
Product Name  : <input type="text" name="product_name">
<br><br>
Category      : <input type="text" name="product_category">
<br><br>
Price         : <input type="price" name="product_price">
<br><br>
<input type="hidden" name="uuid" value="<% out.print(uuid); %>" >
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<button type="submit" formaction="/sample/addproduct.jsp">Add</button>
</form>

</body>
</html>
