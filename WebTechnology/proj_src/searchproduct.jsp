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
         response.sendRedirect("/sample/home.jsp");
   }
   if(uuid.startsWith("\"")){
    uuid = uuid.substring(1,uuid.length()-1);
   }
   System.out.println("View Products uuid = " + uuid);
   String search_product_id = request.getParameter("search_product_id");
   if(search_product_id == null) search_product_id = "";

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
   <a href=searchproduct.jsp?uuid="<% out.print(uuid); %>" >Search Product</a>
    <a href=logout.jsp?uuid="<% out.print(uuid); %>" >Logout</a>
</div>

<h1> Product Management System </h1>
</div>

        <br><br><br>
        <form action="/sample/searchproduct.jsp" method="get">
        Product ID    : <input type="text" name="search_product_id">
        <input type="hidden" name="uuid" value="<% out.print(uuid); %>" >
        <br><br>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <button type="submit" formaction="/sample/searchproduct.jsp">Search</button>
        </form>

        <% if(!search_product_id.equals("")){ %>

        <TABLE>
          <TR><TH border=1>ID</TH><TH border=1>Name</TH><TH border=1>Category</TH><TH border=1>Price</TH></TR>
        <%
            try {
                 query = "select * from products where id = ?";
                 stmt = con.prepareStatement(query);
                 stmt.setString(1,search_product_id);
                 rs = stmt.executeQuery();
                 while (rs.next()) {
        %>
                  <TR >
                      <TD border=1> <%= rs.getString(1) %> </TD>
                      <TD border=1> <%= rs.getString(2) %> </TD>
                      <TD border=1> <%= rs.getString(3) %> </TD>
                      <TD border=1> <%= rs.getString(4) %> </TD>
                  </TR>

        <%
                 }
        %>
        </TABLE>
        <%
            } catch(Throwable t){
                t.printStackTrace();
            }
            finally {
                 if (con!=null) { con.close(); }
            }
        }
        %>

</body>
</html>
