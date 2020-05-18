<%@ page import="javax.naming.*" %>
<%@ page import="java.util.*" %>
<%@ page import="java.sql.*" %>
<%@ page import="javax.sql.*" %>
<%@ page import="org.h2.jdbcx.JdbcDataSource" %>

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

<%
   String uuid = request.getParameter("uuid");
   String product_id = request.getParameter("product_id");
   System.out.println("uuid = " + uuid + " product_id = "+ product_id);
   if (uuid == null){
      response.sendRedirect("/sample/login.html");
   }

 %>

<div class="navbar">
   <a href="home.jsp?uuid="+uuid>Home</a>
   <a href="viewproducts.jsp?uuid="+uuid>View Products</a>
   <a href="searchproduct.jsp?uuid="+uuid>Search Products</a>

 </div>


</div>

        <br><br><br>

        <%
            if(product_id == null || product_id.equals("")){

        %>
            <form action="/sample/searchproduct.jsp" method="get">
                Enter Product ID <input type="text" name="product_id">
                <input type="hidden" name="uuid" value="" <%  System.out.println(uuid); %> >
                <button type="submit" formaction="/sample/searchproduct.jsp">Search</button>
            </form>
        <%
            }
            else{
        %>
            <TABLE>
               <TR><TH border=1>ID</TH><TH border=1>Name</TH><TH border=1>Category</TH><TH border=1>Price</TH></TR>

        <%
            }
        %>

</body>
</html>
