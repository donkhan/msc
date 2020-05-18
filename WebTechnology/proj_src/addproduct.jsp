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
   System.out.println("Add Product uuid = " + uuid);
   if (uuid == null || uuid.equals("")){
    response.sendRedirect("/prod/home.jsp");
   }
   if(uuid.startsWith("\"")){
    uuid = uuid.substring(1,uuid.length()-1);
   }
   if (uuid.equals("")){
    response.sendRedirect("/prod/home.jsp");
   }

   String product_id = request.getParameter("product_id");
   String product_name = request.getParameter("product_name");
   String product_category = request.getParameter("product_category");
   String product_price = request.getParameter("product_price");
   System.out.println("New Product id " + product_id + " product name " + product_name);

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
    response.sendRedirect("/prod/home.jsp");
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
    <a href=logout.jsp?uuid="<% out.print(uuid); %>" >Logout</a>
</div>

<h1> Product Management System </h1>
<form action="/prod/addproduct.jsp" method="get" align="center">

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
<button type="submit" formaction="/prod/addproduct.jsp">Add</button>
</form>

</body>
</html>
