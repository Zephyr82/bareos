/*
   BAREOS® - Backup Archiving REcovery Open Sourced

   Copyright (C) 2019-2021 Bareos GmbH & Co. KG

   This program is Free Software; you can redistribute it and/or
   modify it under the terms of version three of the GNU Affero General Public
   License as published by the Free Software Foundation and included
   in the file LICENSE.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
   Affero General Public License for more details.

   You should have received a copy of the GNU Affero General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
   02110-1301, USA.
*/
#if defined(HAVE_MINGW)
#  include "include/bareos.h"
#  include "gtest/gtest.h"
#else
#  include "gtest/gtest.h"
#  include "include/bareos.h"
#endif

#include "lib/address_conf.h"

TEST(address_conf, IsSameIpAddress)
{
  IPADDR* addr_ipv4 = new IPADDR(AF_INET);
  IPADDR* addr_ipv6 = new IPADDR(AF_INET6);

  EXPECT_FALSE(IsSameIpAddress(addr_ipv4, addr_ipv6));

  IPADDR* clone4(addr_ipv4);
  IPADDR* clone6(addr_ipv6);

  EXPECT_TRUE(IsSameIpAddress(addr_ipv4, clone4));
  EXPECT_TRUE(IsSameIpAddress(addr_ipv6, clone6));
}

