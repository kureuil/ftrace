# -*- coding: utf-8 -*-
import scrapy


class TableSpider(scrapy.Spider):
    name = "table"
    allowed_domains = ["https://filippo.io/"]
    start_urls = (
        'https://filippo.io/linux-syscall-table/',
    )
    typetable = {
        'fd': 'T_INTEGER',
        'count': 'T_SIZE_T',
        'flags': 'T_INTEGER',
        'filename': 'T_STRING',
        'offset': 'T_ULONG',
        'addr': 'T_POINTER',
        'len': 'T_SIZE_T',
        'prot': 'T_INTEGER',
        'off': 'T_ULONG',
        'start': 'T_POINTER',
        'brk': 'T_ULONG',
        'sig': 'T_INTEGER',
        'sigsetsize': 'T_SIZE_T',
        'mode': 'T_INTEGER',
        'oldfd': 'T_INTEGER',
        'newfd': 'T_INTEGER',
        'error_code': 'T_INTEGER',
        'pid': 'T_INTEGER',
        'upid': 'T_INTEGER',
        'gpid': 'T_INTEGER',
        'uid': 'T_INTEGER',
        'euid': 'T_INTEGER',
        'ruid': 'T_INTEGER',
        'gid': 'T_INTEGER',
        'egid': 'T_INTEGER',
        'rgid': 'T_INTEGER',
        'options': 'T_INTEGER',
        'path': 'T_STRING',
        'length': 'T_SIZE_T',
        'size': 'T_SIZE_T',
        'oldname': 'T_STRING',
        'newname': 'T_STRING',
        'pathname': 'T_STRING',
        'name': 'T_STRING',
        'dfd': 'T_INTEGER',
        'olddfd': 'T_INTEGER',
        'newdfd': 'T_INTEGER',
    }

    def parse(self, response):
        count = int(float(response.xpath('count(//tr[@class="tbls-entry-collapsed"])').extract()[0]))
        for i in range(count):
            syscall = response.xpath('//tr[@class="tbls-entry-collapsed"][{}]'.format(i))
            args = syscall.xpath('following-sibling::tr[1]')
            if not args:
                continue
            if 'tbls-arguments-collapsed' not in args.xpath('@class').extract():
                args = None
            # args = response.xpath('//tr[@class="tbls-arguments-collapsed"][{}]'.format(i))
            syscall_id = -1
            for s in syscall.xpath('td[1]/text()').extract():
                syscall_id = int(s)
            syscall_name = ""
            for s in syscall.xpath('td[2]/text()').extract():
                syscall_name = s
            argc = 0
            if args:
                for s in args.xpath('count(td/table/tbody/tr[2]/td)').extract():
                    argc = int(float(s))
            scall = {
                'id': syscall_id,
                'name': syscall_name,
                'argc': argc
            }
            serialized = """    {
        .id = %d,
        .name = "%s",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = %d,
        .args = {""" % (syscall_id, syscall_name, argc)
            arguments = ()
            if args:
                arguments = args.xpath('td/table/tbody/tr[2]/td/text()').extract()
            if (len(arguments)):
                for s in arguments:
                    argtype = self.typetable.get(s.strip(), 'T_DEFAULT')
                    serialized += """
            {
                .custom = false,
                .printer = {
                    .type = %s
                }
            },""" % (argtype)
            else:
                serialized += """
            { 0 }"""
            serialized += """
        }
    },"""
            if syscall_id != -1:
                print(serialized)
