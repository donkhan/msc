<!DOCTYPE html>
<html>
    <jsp:include page="style.jsp">
            <jsp:param name="style" value="" />
    </jsp:include>
<body>

<%@ page import="javax.naming.*" %>
<%@ page import="java.util.*" %>
<%@ page import="java.sql.*" %>
<%@ page import="javax.sql.*" %>
<%@ page import="org.h2.jdbcx.JdbcDataSource" %>
<%
   String uuid = request.getParameter("uuid");
   if (uuid == null){
         response.sendRedirect("/prod/home.jsp");
   }
   if(uuid.startsWith("\"")){
    uuid = uuid.substring(1,uuid.length()-1);
   }
   System.out.println("Edit Product uuid = " + uuid);
   String product_id = request.getParameter("product_id");
   String product_name = request.getParameter("product_name");
   String product_category = request.getParameter("product_category");
   String product_price = request.getParameter("product_price");
   double price = 0;
   System.out.println("Edit Product id " + product_id + " product name " + product_name + " product price " + product_price);
   System.out.println("Product Category " + product_category);

   if( product_id == null) product_id = "";
   if( product_name == null) product_name = "";
   if( product_category == null) product_category = "";
   if( product_price == null) product_price = "";

   if(product_price != null && !product_price.equals("")){
    price = Double.parseDouble(product_price);
   }

   Context ctx = new InitialContext();
   Context initCtx  = (Context) ctx.lookup("java:/comp/env");
   DataSource ds = (DataSource) initCtx.lookup("jdbc/MyLocalDB");
   Connection con = ds.getConnection();
   con.setAutoCommit(false);
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
    response.sendRedirect("/prod/home.jsp");
   }

   if(!product_id.equals("") && !product_name.equals("") && !product_category.equals("") && !product_price.equals("")){
      query = "update products set name = ?, category = ?, price = ?"
                     + " where id = ?";
      stmt = con.prepareStatement(query);
      stmt.setString(1,product_name);
      stmt.setString(2,product_category);
      stmt.setDouble(3,Double.parseDouble(product_price));
      stmt.setString(4,product_id);
      stmt.executeUpdate();
      con.commit();
      response.sendRedirect("/prod/viewproducts.jsp?uuid=" + uuid);
   }
   else{
     query = "select * from products where id = ?";
     stmt = con.prepareStatement(query);
     stmt.setString(1,product_id);
     rs = stmt.executeQuery();
     rs.next();
     product_name = rs.getString(2);
     product_category = rs.getString(3);
     price = rs.getDouble(4);
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
<form action="/prod/editproduct.jsp" method="get">

<br><br><br><br>
Product Name  : <input type="text" name="product_name" value="<% out.println(product_name); %>">
<br><br>
Category      : <input type="text" name="product_category" value="<% out.println(product_category); %>">
<br><br>
Price         : <input type="price" name="product_price" value="<% out.println(price); %>">
<br><br>
<input type="hidden" name="uuid" value="<% out.print(uuid); %>" >
<input type="hidden" name="product_id" value="<% out.print(product_id); %>" >

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<button type="submit" formaction="/prod/editproduct.jsp">Edit</button>
</form>

</body>
</html>
