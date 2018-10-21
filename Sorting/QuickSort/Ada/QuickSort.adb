with Ada.Containers.Vectors;
with Ada.Numerics.Discrete_Random;
with Ada.Text_IO;
with Ada.Integer_Text_IO;

use Ada.Text_IO;
use Ada.Integer_Text_IO;

procedure Quick_Sort is

   ------------------------------
   -- Constant, types, package --
   ------------------------------

   ARRAY_SIZE : constant Natural := 10;
   RANGE_MIN  : constant Integer := 1;
   RANGE_MAX  : constant Integer := 100;

   package P_Vectors is new Ada.Containers.Vectors (Positive, Integer);
   use P_Vectors;

   -----------------------
   --  Method prototype --
   -----------------------

   --  Initializing an array with default values
   function Init_Vector return Vector;

   procedure Put (Tab : Vector);

   procedure Swap (a : in out Integer; b : in out Integer);

   function Sort (T : Vector) return Vector;

   -----------------------------
   --  Declaration of methods --
   -----------------------------

   function Init_Vector return Vector
   is
      subtype T_Interval is Integer range RANGE_MIN .. RANGE_MAX;
      package P_Random is new Ada.numerics.discrete_random (T_Interval);
      use P_Random;

      seed : Generator;
      T    : Vector;
   begin
      Reset (seed);

      for i in 1 .. ARRAY_SIZE loop
         Append (T, Random (seed));
      end loop;

      return T;
   end Init_Vector;

   procedure Put (Tab : Vector)
   is
   begin
      for e of Tab loop
         Put (e, Width => 0);
         Put (";");
      end loop;
   end Put;

   procedure Swap (a : in out Integer; b : in out Integer)
   is
      c : constant Integer := a;
   begin
      a := b;
      b := c;
   end Swap;

   function Sort (T : Vector) return Vector
   is

      -----------------------
      --  Method prototype --
      -----------------------

      procedure Sort (T           : in out Vector;
                      First, Last :        Integer);

      -----------------------------
      --  Declaration of methods --
      -----------------------------

      procedure Sort (T           : in out Vector;
                      First, Last :        Integer)
      is
         Pivot : Integer := (First + Last) / 2;
         j     : Integer := First + 1;
      begin
         if First < Last then
            Swap (T (First), T (Pivot));
            Pivot := First;
            for i in First + 1 .. Last loop
               if T (i) < T (Pivot) then
                  Swap (T (i), T (j));
                  j := j + 1;
               end if;
            end loop;

            Swap (T (Pivot), T (j - 1));
            Pivot := j - 1;

            Sort (T, First, Pivot - 1);
            Sort (T, Pivot + 1, Last);
         end if;
      end Sort;

      ---------------
      -- Variables --
      ---------------

      Tab : Vector := T;
   begin
      Sort (Tab, First_Index (Tab), Last_Index (Tab));
      return Tab;
   end Sort;

   ---------------
   -- Variables --
   ---------------

   T : Vector := Init_Vector;
begin
   Put ("Array        : ");
   Put (T);
   New_Line;

   T := Sort (T);

   Put ("Sorted array : ");
   Put (T);
end Quick_Sort;
