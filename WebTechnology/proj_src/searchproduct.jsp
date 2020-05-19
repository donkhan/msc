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
   System.out.println("Search Product uuid = " + uuid);
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
    response.sendRedirect("/prod/home.jsp");
   }
 %>

<%
    request.setAttribute("uuid",uuid);
    request.setAttribute("query","select * from products where id = ?");
%>
<jsp:include page="navbar.jsp">
     <jsp:param name="uuid" value="${uuid}" />
</jsp:include>

<h1> Product Management System </h1>
</div>

        <br><br><br>
        <form action="/prod/searchproduct.jsp" method="get" align="center">
        Product ID    : <input type="text" name="search_product_id">
        <input type="hidden" name="uuid" value="<% out.print(uuid); %>" >
        <br><br>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <button type="submit" formaction="/prod/searchproduct.jsp">Search</button>
        </form>

        <% if(!search_product_id.equals("")){
            request.setAttribute("product_id",search_product_id);
        %>
            <jsp:include page="list_products.jsp">
                 <jsp:param name="uuid" value="${uuid}" />
                 <jsp:param name="query" value="${query}" />
                 <jsp:param name="product_id" value="${product_id}" />
            </jsp:include>

        <% } %>

</body>
</html>